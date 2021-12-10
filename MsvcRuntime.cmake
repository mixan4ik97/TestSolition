macro(configure_msvc_runtime) #replace MDd->MTd, MD->MT #TODO this is hardcoded replace
if( MSVC )
	message(STATUS "Using Visual Studio (CMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER})")
	set(variables
		CMAKE_C_FLAGS_DEBUG
		CMAKE_C_FLAGS_MINSIZEREL
		CMAKE_C_FLAGS_RELEASE
		CMAKE_C_FLAGS_RELWITHDEBINFO
		CMAKE_C_FLAGS
		CMAKE_CXX_FLAGS_DEBUG
		CMAKE_CXX_FLAGS_MINSIZEREL
		CMAKE_CXX_FLAGS_RELEASE
		CMAKE_CXX_FLAGS_RELWITHDEBINFO
		CMAKE_CXX_FLAGS
	)

	if(USE_STATIC_MSVC_CRT)
		message("Using CRT as static library (/MTd, /MT)")
		foreach(variable ${variables})
			if(${variable} MATCHES "/MDd")
			string(REGEX REPLACE "/MDd" "/MTd" ${variable} "${${variable}}")
			endif()
			if(${variable} MATCHES "/MD")
			string(REGEX REPLACE "/MD" "/MT" ${variable} "${${variable}}")
			endif()
		endforeach()
	else(USE_STATIC_MSVC_CRT)
		message("Using CRT as shared library (/MDd, /MD)")
		foreach(variable ${variables})
			if(${variable} MATCHES "/MTd")
			string(REGEX REPLACE "/MTd" "/MDd" ${variable} "${${variable}}")
			endif()
			if(${variable} MATCHES "/MT")
			string(REGEX REPLACE "/MT" "/MD" ${variable} "${${variable}}")
			endif()
		endforeach()
	endif(USE_STATIC_MSVC_CRT)
	
	#for testMemManager() function it is required to use /EHa visual c++ flag
	if(USE_SEH_IN_CATCH)
		message("Using SEH in catch blocks (/EHa)")
		foreach(variable ${variables})
			if(${variable} MATCHES "/EHsc")
				string(REGEX REPLACE "/EHsc" "/EHa" ${variable} "${${variable}}")
			endif()
		endforeach()
	else(USE_SEH_IN_CATCH)
		message("Not using SEH in catch blocks (do not use the testMemManager function)")
	endif(USE_SEH_IN_CATCH)

ENDIF(MSVC)
endmacro()
