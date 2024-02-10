**[[#^f8292a|Params:]]**
	GLuint *width*
	GLuint *height*
	const char* *title*
**Returns:**
	[[#^8c2062|int]]


**Overview**
	Ensures system compatibility with the chosen [[rendering API]], performs initialization of external rendering libraries, and creates a window for the application to run in.

**Parameter Information**
	***width:***
		The horizontal size of the executable window
	***height:***
		The vertical size of the executable window
	***title:***
		The title of the window ^f8292a

**Return Information**
	Integer value set to:
	0 on success, 
	-1 on error ^8c2062