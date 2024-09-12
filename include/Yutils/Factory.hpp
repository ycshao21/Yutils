#include <mutex>
#include <optional>
#include <shared_mutex>
#include <unordered_map>

#include "Yutils/System.hpp"

namespace yutils
{
template <typename KeyT, typename CreatorT,
          typename ContainerT = std::unordered_map<KeyT, CreatorT>>
class Factory
{
public:
    explicit Factory() = default;
    Factory& operator=(const Factory&) = delete;

public:
    void registerCreator(const KeyT& key, const CreatorT& creator)
    {
        std::unique_lock<std::shared_mutex> lock(m_mutex);
        m_container[key] = creator;
    }

    void unregisterCreator(const KeyT& key)
    {
        std::unique_lock<std::shared_mutex> lock(m_mutex);
        m_container.erase(key);
    }

    template <typename... Args>
    auto create(const KeyT& key, Args&&... args)
    {
        std::shared_lock<std::shared_mutex> lock(m_mutex);
        using ValT =
            decltype(m_container.begin()->second(std::forward<Args>(args)...));
        auto it = m_container.find(key);
        // Return the result of the creator function if key found.
        if (it != m_container.end()) {
            return std::optional<ValT>{it->second(std::forward<Args>(args)...)};
        }
        // Return empty optional if key not found.
        return std::optional<ValT>{};
    }

    std::optional<CreatorT> getCreator(const KeyT& key) const
    {
        std::shared_lock<std::shared_mutex> lock(m_mutex);
        auto it = m_container.find(key);
        // Return the creator function if key found.
        if (it != m_container.end()) {
            return std::optional<CreatorT>{it->second};
        }
        // Return empty optional if key not found.
        return std::optional<CreatorT>{};
    }

private:
    mutable std::shared_mutex m_mutex;
    ContainerT m_container;
};

}  // namespace yutils