add_library(ece2400-sec09-lib
    ece2400-stdlib.cc
    SListInt.cc
    SListIObj.cc
    types-dpoly.cc
)

function(add_pa_exec bin srcs)
  add_executable(${bin} ${srcs})
  target_link_libraries(${bin} PUBLIC
    ece2400-sec09-lib
    m # math
  )
endfunction()

add_pa_exec(slist-dpoly-adhoc slist-dpoly-adhoc.cc)
add_pa_exec(slist-int-adhoc slist-int-adhoc.cc)

function(add_pa_test bin srcs)
  add_pa_exec(${bin} ${srcs})
  add_test(NAME ${bin}
         COMMAND ${bin})
endfunction()
