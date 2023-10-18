file(GLOB entries *)
foreach(entry ${entries})
    if(IS_DIRECTORY ${entry})
        get_filename_component(origin_entry_name "${entry}" NAME)

        if(NOT (IS_DIRECTORY ${entry}) OR (NOT (EXISTS ${entry}/CMakeLists.txt)))
            continue()
        endif()

        #if(${origin_entry_name} STREQUAL "asdklfhgkasdgasdgah")

            #elseif(${origin_entry_name} STREQUAL "cmake-tests")
        #elseif()
            #add_subdirectory(${entry})
            #set_target_properties(${origin_entry_name} PROPERTIES FOLDER "projects")  
            #message(STATIC "${entry}/")
        #endif()

        add_subdirectory(${entry})
        #MESSAGE(${entry})
    endif()
endforeach(entry)
