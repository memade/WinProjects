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
		#if(${origin_entry_name} STREQUAL "devtools")
			#add_subdirectory(${entry})
			#set(target_project_relative_path_name "")
			#GLOBAL_GET_TARGET_PROJECT_RELATIVE_PATHNAME(${entry} target_project_relative_path_name)
			#set_target_properties(${entry_name} PROPERTIES FOLDER ${target_project_relative_path_name})
		#elseif()
			add_subdirectory(${entry})
		#endif()
        #MESSAGE(${entry})
    endif()
endforeach(entry)
