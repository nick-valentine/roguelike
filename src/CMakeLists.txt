add_subdirectory (window)
add_subdirectory (objects)
add_subdirectory (utility)
add_subdirectory (levelPass)

SET (SOURCES
	${SOURCES}
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
	PARENT_SCOPE
)