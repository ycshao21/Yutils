string(ASCII 27 Esc)
set(CYAN_CAT "${Esc}[0;36mᓚᘏᗢ${Esc}[m")

set(LOG_PREFIX "Yutils♪")

function(log_info msg)
    message(STATUS "[${LOG_PREFIX}|INFO] >>> ${msg}")
endfunction(log_info msg)

function(log_warning msg)
    message(WARNING "[${LOG_PREFIX}|WARNING] >>> ${msg}")
endfunction(log_warning msg)

function(log_error msg)
    message(SEND_ERROR "[${LOG_PREFIX}|ERROR] >>> ${msg}")
endfunction(log_error msg)

function(log_fatal msg)
    message(FATAL_ERROR "[${LOG_PREFIX}|FATAL] >>> ${msg}")
endfunction(log_fatal msg)