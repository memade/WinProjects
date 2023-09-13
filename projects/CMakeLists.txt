file(GLOB entries *)
foreach(entry ${entries})
	if(IS_DIRECTORY ${entry})
		get_filename_component(origin_entry_name "${entry}" NAME)
  
  if(${origin_entry_name} STREQUAL "asdklfhgkasdgasdgah")
  
  elseif(${origin_entry_name} STREQUAL "framework")
   add_subdirectory(${entry})
   #set_target_properties(${origin_entry_name} PROPERTIES FOLDER "projects")  
   #message(STATIC "${entry}/")
  endif()
 endif()
endforeach(entry)
