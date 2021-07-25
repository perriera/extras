 
add_library(
    docopt SHARED
	include/docopt_private.h    
    include/docopt_util.h         
    include/docopt_value.h           
    include/docopt.h  
    src/docopt.cpp  
)

target_link_libraries(docopt 
    PRIVATE
        extra
)

target_compile_features(docopt
	PUBLIC
		cxx_std_11
)
