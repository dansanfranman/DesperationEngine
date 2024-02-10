**params:**
	none
**Returns:**
	[[#^8c2062|int]]

**Overview**
	Renders the scene in its current state to the back buffer then switches the front and back buffers to display the written frame to the user
**Design Logic**
	With the aim of maximizing performance the renderer will iterate over all loaded [[shaders]], rendering all associated [[models]] before proceeding to the next [[shader]]. Each [[shader]] will hold a pointer to an array of [[models]] that it should render. This ensures that each [[shader]] is only loaded onto the GPU once per frame, and that the [[models]] this shader will be active for are stored contiguously in memory.

**Return Information
	Integer value set to:
	0 on success, 
	-1 on error ^8c2062