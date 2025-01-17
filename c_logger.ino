/**
 * @file    c_logger.ino
 * @brief   Library of logging macros for different severity levels.
 * @details This library defines macros for generating logging messages at
 *          different severity levels (TRACE, DEBUG, INFO, WARN, ERROR, FATAL).
 *          The logging level is controlled via the LOG_LEVEL macro. If LOG_LEVEL is not defined,
 *          all logging macros are disabled. Messages are printed using Serial.print().
 *
 * @par
 * COPYRIGHT NOTICE: (c) 2024 Andrea Nieto Gil. All rights reserved.
 */

// Define severity levels
#define TRACE 6
#define DEBUG 5
#define INFO 4
#define WARN 3
#define ERROR 2
#define FATAL 1
#define NONE 0

#ifdef LOG_LEVEL  // Check if LOG_LEVEL is defined
bool _log_newline = true;  // Track if a newline is needed

// Define macros for each severity level, checking if LOG_LEVEL is high enough
#define trace(message)   if ( LOG_LEVEL >= TRACE ) { if (_log_newline) Serial.print("[TRACE] "); Serial.print(message);   _log_newline = false;}
#define traceln(message) if ( LOG_LEVEL >= TRACE ) { if (_log_newline) Serial.print("[TRACE] "); Serial.println(message); _log_newline = true;}
#define debug(message)   if ( LOG_LEVEL >= DEBUG ) { if (_log_newline) Serial.print("[DEBUG] "); Serial.print(message);   _log_newline = false;}
#define debugln(message) if ( LOG_LEVEL >= DEBUG ) { if (_log_newline) Serial.print("[DEBUG] "); Serial.println(message); _log_newline = true;}
#define info(message)    if ( LOG_LEVEL >= INFO  ) { if (_log_newline) Serial.print("[ INFO] "); Serial.print(message);   _log_newline = false;}
#define infoln(message)  if ( LOG_LEVEL >= INFO  ) { if (_log_newline) Serial.print("[ INFO] "); Serial.println(message); _log_newline = true;}
#define warn(message)    if ( LOG_LEVEL >= WARN  ) { if (_log_newline) Serial.print("[ WARN] "); Serial.print(message);   _log_newline = false;}
#define warnln(message)  if ( LOG_LEVEL >= WARN  ) { if (_log_newline) Serial.print("[ WARN] "); Serial.println(message); _log_newline = true;}
#define error(message)   if ( LOG_LEVEL >= ERROR ) { if (_log_newline) Serial.print("[ERROR] "); Serial.print(message);   _log_newline = false;}
#define errorln(message) if ( LOG_LEVEL >= ERROR ) { if (_log_newline) Serial.print("[ERROR] "); Serial.println(message); _log_newline = true;}
#define fatal(message)   if ( LOG_LEVEL >= FATAL ) { if (_log_newline) Serial.print("[FATAL] "); Serial.print(message);   _log_newline = false;}
#define fatalln(message) if ( LOG_LEVEL >= FATAL ) { if (_log_newline) Serial.print("[FATAL] "); Serial.println(message); _log_newline = true;}

#else  // If LOG_LEVEL is not defined, define empty macros
#define trace(message)
#define traceln(message)
#define debug(message)
#define debugln(message)
#define info(message)
#define infoln(message)
#define warn(message)
#define warnln(message)
#define error(message)
#define errorln(message)
#define fatal(message)
#define fatalln(message)

#endif // LOG_LEVEL

/*** End of file ****/