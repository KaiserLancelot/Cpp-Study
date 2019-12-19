function(append value)
  foreach(variable ${ARGN})
    set(${variable}
        "${${variable}} ${value}"
        PARENT_SCOPE)
  endforeach(variable)
endfunction()

if(sanitizer MATCHES "([Nn]one)")
  message(STATUS "None sanitizer")
else()
  if(sanitizer MATCHES "([Aa]ddress)")
    message(STATUS "Building with Address sanitizer")
    append("-fsanitize=address -fno-omit-frame-pointer -O1" CMAKE_CXX_FLAGS)
  elseif(sanitizer MATCHES "([Tt]hread)")
    message(STATUS "Building with Thread sanitizer")
    append("-fsanitize=thread -O2" CMAKE_CXX_FLAGS)
  elseif(sanitizer MATCHES "([Uu]ndefined)")
    message(STATUS "Building with Undefined sanitizer")
    append("-fsanitize=undefined" CMAKE_CXX_FLAGS)
  else()
    message(FATAL_ERROR "Sanitizer is not supported")
  endif()
endif()
