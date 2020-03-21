
#include "onyx/includes/display/window__OSX__backend.h"

#include <Cocoa/Cocoa.h>
#include <QuartzCore/QuartzCore.h>

void initApp()
{
	[NSApplication sharedApplication];
	[NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
}

const void *createWindow(enum Style eStyle, int nMinX, int nMinY, int nMaxX, int nMaxY, const char *pTitle)
{
	CGFloat nMinXF = (CGFloat)nMinX;
	CGFloat nMinYF = (CGFloat)nMinY;
	CGFloat nMaxXF = (CGFloat)nMaxX;
	CGFloat nMaxYF = (CGFloat)nMaxY;

	NSUInteger nStyle;

	switch (eStyle) {
	case ContentOnly: nStyle = NSWindowStyleMaskBorderless; break;
	case Title: nStyle = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable; break;
	case TitleResizable:
		nStyle = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable
				 | NSWindowStyleMaskResizable;
		break;
	case Standard:
		nStyle = NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskMiniaturizable
				 | NSWindowStyleMaskResizable;
		break;
	default: return nil;
	}

	NSWindow *pNSWindow =
		[[NSWindow alloc] initWithContentRect:NSMakeRect(nMinXF, nMinYF, nMaxXF - nMinXF, nMaxYF - nMinYF)
									styleMask:nStyle
									  backing:NSBackingStoreBuffered
										defer:NO];

	pNSWindow.releasedWhenClosed	 = YES;
	pNSWindow.contentView.wantsLayer = YES;
	pNSWindow.contentView.layer		 = [CAMetalLayer layer];
	[pNSWindow center];

	return CFBridgingRetain(pNSWindow);
}

void destroyWindow(const void *pWindow)
{
	[CFBridgingRelease(pWindow) close];
}

const void *getMetalView(const void *pWindow)
{
	return (__bridge const void *)((__bridge NSWindow *)pWindow).contentView;
}

void loopEvent()
{
	[NSApp run];
}

void loopEventAvailable(const void *pWindow)
{
	NSWindow *pNSWindow = (__bridge NSWindow *)pWindow;

	for (;;) {
		NSEvent *pEvent = [pNSWindow nextEventMatchingMask:NSEventMaskAny
												 untilDate:nil
													inMode:NSDefaultRunLoopMode
												   dequeue:YES];

		if (!pEvent) break;

		[NSApp sendEvent:pEvent];
	}
}

void setTitle(const void *pWindow, const char *pTitle)
{
	[(__bridge NSWindow *)pWindow setTitle:[NSString stringWithUTF8String:pTitle]];
}

void setVisibility(const void *pWindow, enum Visibility eVisibility)
{
	NSWindow *pNSWindow = (__bridge NSWindow *)(pWindow);

	switch (eVisibility) {
	case Invisible: {
		[pNSWindow orderOut:pNSWindow];
	} break;
	case VisibleDefault: {
		[pNSWindow makeKeyAndOrderFront:nil];
		[NSApp activateIgnoringOtherApps:YES];
	} break;
	case VisibleMinimized: {
		// TODO: TO be implemented.
	} break;
	case VisibleMaximized: {
		// TODO: TO be implemented.
	} break;
	}
}