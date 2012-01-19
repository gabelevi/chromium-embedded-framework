// Copyright (c) 2012 Marshall A. Greenblatt. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//    * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//    * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//    * Neither the name of Google Inc. nor the name Chromium Embedded
// Framework nor the names of its contributors may be used to endorse
// or promote products derived from this software without specific prior
// written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool and should not edited
// by hand. See the translator.README.txt file in the tools directory for
// more information.
//

#ifndef CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_
#define CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_
#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "include/capi/cef_base_capi.h"


///
// Structure used to represent a browser window. The functions of this structure
// may be called on any thread unless otherwise indicated in the comments.
///
typedef struct _cef_browser_t {
  ///
  // Base structure.
  ///
  cef_base_t base;

  ///
  // Call this function before destroying a contained browser window. This
  // function performs any internal cleanup that may be needed before the
  // browser window is destroyed.
  ///
  void (CEF_CALLBACK *parent_window_will_close)(struct _cef_browser_t* self);

  ///
  // Closes this browser window.
  ///
  void (CEF_CALLBACK *close_browser)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser can navigate backwards.
  ///
  int (CEF_CALLBACK *can_go_back)(struct _cef_browser_t* self);

  ///
  // Navigate backwards.
  ///
  void (CEF_CALLBACK *go_back)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if the browser can navigate forwards.
  ///
  int (CEF_CALLBACK *can_go_forward)(struct _cef_browser_t* self);

  ///
  // Navigate forwards.
  ///
  void (CEF_CALLBACK *go_forward)(struct _cef_browser_t* self);

  ///
  // Reload the current page.
  ///
  void (CEF_CALLBACK *reload)(struct _cef_browser_t* self);

  ///
  // Reload the current page ignoring any cached data.
  ///
  void (CEF_CALLBACK *reload_ignore_cache)(struct _cef_browser_t* self);

  ///
  // Stop loading the page.
  ///
  void (CEF_CALLBACK *stop_load)(struct _cef_browser_t* self);

  ///
  // Set focus for the browser window. If |enable| is true (1) focus will be set
  // to the window. Otherwise, focus will be removed.
  ///
  void (CEF_CALLBACK *set_focus)(struct _cef_browser_t* self, int enable);

  ///
  // Retrieve the window handle for this browser.
  ///
  cef_window_handle_t (CEF_CALLBACK *get_window_handle)(
      struct _cef_browser_t* self);

  ///
  // Retrieve the window handle of the browser that opened this browser. Will
  // return NULL for non-popup windows. This function can be used in combination
  // with custom handling of modal windows.
  ///
  cef_window_handle_t (CEF_CALLBACK *get_opener_window_handle)(
      struct _cef_browser_t* self);

  ///
  // Returns true (1) if the window is a popup window.
  ///
  int (CEF_CALLBACK *is_popup)(struct _cef_browser_t* self);

  // Returns true (1) if a document has been loaded in the browser.
  int (CEF_CALLBACK *has_document)(struct _cef_browser_t* self);

  ///
  // Returns the client for this browser.
  ///
  struct _cef_client_t* (CEF_CALLBACK *get_client)(struct _cef_browser_t* self);

  ///
  // Returns the main (top-level) frame for the browser window.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_main_frame)(
      struct _cef_browser_t* self);

  ///
  // Returns the focused frame for the browser window. This function should only
  // be called on the UI thread.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_focused_frame)(
      struct _cef_browser_t* self);

  ///
  // Returns the frame with the specified name, or NULL if not found. This
  // function should only be called on the UI thread.
  ///
  struct _cef_frame_t* (CEF_CALLBACK *get_frame)(struct _cef_browser_t* self,
      const cef_string_t* name);

  ///
  // Returns the names of all existing frames. This function should only be
  // called on the UI thread.
  ///
  void (CEF_CALLBACK *get_frame_names)(struct _cef_browser_t* self,
      cef_string_list_t names);

  ///
  // Search for |searchText|. |identifier| can be used to have multiple searches
  // running simultaniously. |forward| indicates whether to search forward or
  // backward within the page. |matchCase| indicates whether the search should
  // be case-sensitive. |findNext| indicates whether this is the first request
  // or a follow-up.
  ///
  void (CEF_CALLBACK *find)(struct _cef_browser_t* self, int identifier,
      const cef_string_t* searchText, int forward, int matchCase,
      int findNext);

  ///
  // Cancel all searches that are currently going on.
  ///
  void (CEF_CALLBACK *stop_finding)(struct _cef_browser_t* self,
      int clearSelection);

  ///
  // Get the zoom level.
  ///
  double (CEF_CALLBACK *get_zoom_level)(struct _cef_browser_t* self);

  ///
  // Change the zoom level to the specified value.
  ///
  void (CEF_CALLBACK *set_zoom_level)(struct _cef_browser_t* self,
      double zoomLevel);

  ///
  // Clear the back/forward browsing history.
  ///
  void (CEF_CALLBACK *clear_history)(struct _cef_browser_t* self);

  ///
  // Open developer tools in its own window.
  ///
  void (CEF_CALLBACK *show_dev_tools)(struct _cef_browser_t* self);

  ///
  // Explicitly close the developer tools window if one exists for this browser
  // instance.
  ///
  void (CEF_CALLBACK *close_dev_tools)(struct _cef_browser_t* self);

  ///
  // Returns true (1) if window rendering is disabled.
  ///
  int (CEF_CALLBACK *is_window_rendering_disabled)(struct _cef_browser_t* self);

  ///
  // Get the size of the specified element. This function should only be called
  // on the UI thread.
  ///
  int (CEF_CALLBACK *get_size)(struct _cef_browser_t* self,
      enum cef_paint_element_type_t type, int* width, int* height);

  ///
  // Set the size of the specified element. This function is only used when
  // window rendering is disabled.
  ///
  void (CEF_CALLBACK *set_size)(struct _cef_browser_t* self,
      enum cef_paint_element_type_t type, int width, int height);

  ///
  // Returns true (1) if a popup is currently visible. This function should only
  // be called on the UI thread.
  ///
  int (CEF_CALLBACK *is_popup_visible)(struct _cef_browser_t* self);

  ///
  // Hide the currently visible popup, if any.
  ///
  void (CEF_CALLBACK *hide_popup)(struct _cef_browser_t* self);

  ///
  // Invalidate the |dirtyRect| region of the view. This function is only used
  // when window rendering is disabled and will result in a call to
  // HandlePaint().
  ///
  void (CEF_CALLBACK *invalidate)(struct _cef_browser_t* self,
      const cef_rect_t* dirtyRect);

  ///
  // Get the raw image data contained in the specified element without
  // performing validation. The specified |width| and |height| dimensions must
  // match the current element size. On Windows |buffer| must be width*height*4
  // bytes in size and represents a BGRA image with an upper-left origin. This
  // function should only be called on the UI thread.
  ///
  int (CEF_CALLBACK *get_image)(struct _cef_browser_t* self,
      enum cef_paint_element_type_t type, int width, int height,
      void* buffer);

  ///
  // Send a key event to the browser.
  ///
  void (CEF_CALLBACK *send_key_event)(struct _cef_browser_t* self,
      enum cef_key_type_t type, int key, int modifiers, int sysChar,
      int imeChar);

  ///
  // Send a mouse click event to the browser. The |x| and |y| coordinates are
  // relative to the upper-left corner of the view.
  ///
  void (CEF_CALLBACK *send_mouse_click_event)(struct _cef_browser_t* self,
      int x, int y, enum cef_mouse_button_type_t type, int mouseUp,
      int clickCount);

  ///
  // Send a mouse move event to the browser. The |x| and |y| coordinates are
  // relative to the upper-left corner of the view.
  ///
  void (CEF_CALLBACK *send_mouse_move_event)(struct _cef_browser_t* self, int x,
      int y, int mouseLeave);

  ///
  // Send a mouse wheel event to the browser. The |x| and |y| coordinates are
  // relative to the upper-left corner of the view.
  ///
  void (CEF_CALLBACK *send_mouse_wheel_event)(struct _cef_browser_t* self,
      int x, int y, int delta);

  ///
  // Send a focus event to the browser.
  ///
  void (CEF_CALLBACK *send_focus_event)(struct _cef_browser_t* self,
      int setFocus);

  ///
  // Send a capture lost event to the browser.
  ///
  void (CEF_CALLBACK *send_capture_lost_event)(struct _cef_browser_t* self);
} cef_browser_t;


///
// Create a new browser window using the window parameters specified by
// |windowInfo|. All values will be copied internally and the actual window will
// be created on the UI thread. This function call will not block.
///
CEF_EXPORT int cef_browser_create(cef_window_info_t* windowInfo,
    struct _cef_client_t* client, const cef_string_t* url,
    const struct _cef_browser_settings_t* settings);

///
// Create a new browser window using the window parameters specified by
// |windowInfo|. This function should only be called on the UI thread.
///
CEF_EXPORT cef_browser_t* cef_browser_create_sync(cef_window_info_t* windowInfo,
    struct _cef_client_t* client, const cef_string_t* url,
    const struct _cef_browser_settings_t* settings);


#ifdef __cplusplus
}
#endif

#endif  // CEF_INCLUDE_CAPI_CEF_BROWSER_CAPI_H_