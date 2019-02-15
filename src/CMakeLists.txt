add_subdirectory (window)
add_subdirectory (objects)
add_subdirectory (utility)
add_subdirectory (levelPass)
add_subdirectory (component)
add_subdirectory (state)

SET (SOURCES
	${SOURCES}
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/input.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/keyMap.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp
	PARENT_SCOPE
)