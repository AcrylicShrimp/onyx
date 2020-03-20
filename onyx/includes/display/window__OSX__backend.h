
#ifdef __cplusplus
extern "C" {
#endif

enum Style { ContentOnly, Title, TitleResizable, Standard };

enum Visibility { Invisible, VisibleDefault, VisibleMinimized, VisibleMaximized };

void		initApp();
const void *createWindow(enum Style eStyle, int nMinX, int nMinY, int nMaxX, int nMaxY, const char *pTitle);
void		destroyWindow(const void *pWindow);
const void *getMetalView(const void *pWindow);
void		loopEvent();
void		loopEventAvailable(const void *pWindow);
void		setTitle(const void *pWindow, const char *pTitle);
void		setVisibility(const void *pWindow, enum Visibility eVisibility);

#ifdef __cplusplus
}
#endif