﻿#pragma once
#ifndef COMMON_GLFW_HPP
#define COMMON_GLFW_HPP
namespace planet {

namespace glfw {
/**
 * マウスカーソルを表示します。
 */
void showCursor();

/**
 * マウスカーソルを非表示にします。
 */
void hideCursor();
/**
 * 指定のキーが押されているなら true を返します。
 * @param keycode
 * @return
 */
int getKey(int keycode);

extern int _glfw3_h_;
extern int Version_major;
extern int Version_minor;
extern int Version_revision;
extern int True;
extern int False;
extern int Release;
extern int Press;
extern int Repeat;
extern int Hat_centered;
extern int Hat_up;
extern int Hat_right;
extern int Hat_down;
extern int Hat_left;
extern int Hat_right_up;
extern int Hat_right_down;
extern int Hat_left_up;
extern int Hat_left_down;
extern int Key_unknown;
extern int Key_space;
extern int Key_apostrophe;
extern int Key_comma;
extern int Key_minus;
extern int Key_period;
extern int Key_slash;
extern int Key_0;
extern int Key_1;
extern int Key_2;
extern int Key_3;
extern int Key_4;
extern int Key_5;
extern int Key_6;
extern int Key_7;
extern int Key_8;
extern int Key_9;
extern int Key_semicolon;
extern int Key_equal;
extern int Key_a;
extern int Key_b;
extern int Key_c;
extern int Key_d;
extern int Key_e;
extern int Key_f;
extern int Key_g;
extern int Key_h;
extern int Key_i;
extern int Key_j;
extern int Key_k;
extern int Key_l;
extern int Key_m;
extern int Key_n;
extern int Key_o;
extern int Key_p;
extern int Key_q;
extern int Key_r;
extern int Key_s;
extern int Key_t;
extern int Key_u;
extern int Key_v;
extern int Key_w;
extern int Key_x;
extern int Key_y;
extern int Key_z;
extern int Key_left_bracket;
extern int Key_backslash;
extern int Key_right_bracket;
extern int Key_grave_accent;
extern int Key_world_1;
extern int Key_world_2;
extern int Key_escape;
extern int Key_enter;
extern int Key_tab;
extern int Key_backspace;
extern int Key_insert;
extern int Key_delete;
extern int Key_right;
extern int Key_left;
extern int Key_down;
extern int Key_up;
extern int Key_page_up;
extern int Key_page_down;
extern int Key_home;
extern int Key_end;
extern int Key_caps_lock;
extern int Key_scroll_lock;
extern int Key_num_lock;
extern int Key_print_screen;
extern int Key_pause;
extern int Key_f1;
extern int Key_f2;
extern int Key_f3;
extern int Key_f4;
extern int Key_f5;
extern int Key_f6;
extern int Key_f7;
extern int Key_f8;
extern int Key_f9;
extern int Key_f10;
extern int Key_f11;
extern int Key_f12;
extern int Key_f13;
extern int Key_f14;
extern int Key_f15;
extern int Key_f16;
extern int Key_f17;
extern int Key_f18;
extern int Key_f19;
extern int Key_f20;
extern int Key_f21;
extern int Key_f22;
extern int Key_f23;
extern int Key_f24;
extern int Key_f25;
extern int Key_kp_0;
extern int Key_kp_1;
extern int Key_kp_2;
extern int Key_kp_3;
extern int Key_kp_4;
extern int Key_kp_5;
extern int Key_kp_6;
extern int Key_kp_7;
extern int Key_kp_8;
extern int Key_kp_9;
extern int Key_kp_decimal;
extern int Key_kp_divide;
extern int Key_kp_multiply;
extern int Key_kp_subtract;
extern int Key_kp_add;
extern int Key_kp_enter;
extern int Key_kp_equal;
extern int Key_left_shift;
extern int Key_left_control;
extern int Key_left_alt;
extern int Key_left_super;
extern int Key_right_shift;
extern int Key_right_control;
extern int Key_right_alt;
extern int Key_right_super;
extern int Key_menu;
extern int Key_last;
extern int Mod_shift;
extern int Mod_control;
extern int Mod_alt;
extern int Mod_super;
extern int Mod_caps_lock;
extern int Mod_num_lock;
extern int Mouse_button_1;
extern int Mouse_button_2;
extern int Mouse_button_3;
extern int Mouse_button_4;
extern int Mouse_button_5;
extern int Mouse_button_6;
extern int Mouse_button_7;
extern int Mouse_button_8;
extern int Mouse_button_last;
extern int Mouse_button_left;
extern int Mouse_button_right;
extern int Mouse_button_middle;
extern int Joystick_1;
extern int Joystick_2;
extern int Joystick_3;
extern int Joystick_4;
extern int Joystick_5;
extern int Joystick_6;
extern int Joystick_7;
extern int Joystick_8;
extern int Joystick_9;
extern int Joystick_10;
extern int Joystick_11;
extern int Joystick_12;
extern int Joystick_13;
extern int Joystick_14;
extern int Joystick_15;
extern int Joystick_16;
extern int Joystick_last;
extern int Gamepad_button_a;
extern int Gamepad_button_b;
extern int Gamepad_button_x;
extern int Gamepad_button_y;
extern int Gamepad_button_left_bumper;
extern int Gamepad_button_right_bumper;
extern int Gamepad_button_back;
extern int Gamepad_button_start;
extern int Gamepad_button_guide;
extern int Gamepad_button_left_thumb;
extern int Gamepad_button_right_thumb;
extern int Gamepad_button_dpad_up;
extern int Gamepad_button_dpad_right;
extern int Gamepad_button_dpad_down;
extern int Gamepad_button_dpad_left;
extern int Gamepad_button_last;
extern int Gamepad_button_cross;
extern int Gamepad_button_circle;
extern int Gamepad_button_square;
extern int Gamepad_button_triangle;
extern int Gamepad_axis_left_x;
extern int Gamepad_axis_left_y;
extern int Gamepad_axis_right_x;
extern int Gamepad_axis_right_y;
extern int Gamepad_axis_left_trigger;
extern int Gamepad_axis_right_trigger;
extern int Gamepad_axis_last;
extern int No_error;
extern int Not_initialized;
extern int No_current_context;
extern int Invalid_enum;
extern int Invalid_value;
extern int Out_of_memory;
extern int Api_unavailable;
extern int Version_unavailable;
extern int Platform_error;
extern int Format_unavailable;
extern int No_window_context;
extern int Focused;
extern int Iconified;
extern int Resizable;
extern int Visible;
extern int Decorated;
extern int Auto_iconify;
extern int Floating;
extern int Maximized;
extern int Center_cursor;
extern int Transparent_framebuffer;
extern int Hovered;
extern int Red_bits;
extern int Green_bits;
extern int Blue_bits;
extern int Alpha_bits;
extern int Depth_bits;
extern int Stencil_bits;
extern int Accum_red_bits;
extern int Accum_green_bits;
extern int Accum_blue_bits;
extern int Accum_alpha_bits;
extern int Aux_buffers;
extern int Stereo;
extern int Samples;
extern int Srgb_capable;
extern int Refresh_rate;
extern int Doublebuffer;
extern int Client_api;
extern int Context_version_major;
extern int Context_version_minor;
extern int Context_revision;
extern int Context_robustness;
extern int Opengl_forward_compat;
extern int Opengl_debug_context;
extern int Opengl_profile;
extern int Context_release_behavior;
extern int Context_no_error;
extern int Context_creation_api;
extern int Cocoa_retina_framebuffer;
extern int Cocoa_frame_name;
extern int Cocoa_graphics_switching;
extern int X11_class_name;
extern int X11_instance_name;
extern int No_api;
extern int Opengl_api;
extern int Opengl_es_api;
extern int No_robustness;
extern int No_reset_notification;
extern int Lose_context_on_reset;
extern int Opengl_any_profile;
extern int Opengl_core_profile;
extern int Opengl_compat_profile;
extern int Cursor;
extern int Sticky_keys;
extern int Sticky_mouse_buttons;
extern int Lock_key_mods;
extern int Cursor_normal;
extern int Cursor_hidden;
extern int Cursor_disabled;
extern int Any_release_behavior;
extern int Release_behavior_flush;
extern int Release_behavior_none;
extern int Native_context_api;
extern int Egl_context_api;
extern int Osmesa_context_api;
extern int Arrow_cursor;
extern int Ibeam_cursor;
extern int Crosshair_cursor;
extern int Hand_cursor;
extern int Hresize_cursor;
extern int Vresize_cursor;
extern int Connected;
extern int Disconnected;
extern int Joystick_hat_buttons;
extern int Cocoa_chdir_resources;
extern int Cocoa_menubar;
extern int Dont_care;
}  // namespace glfw
}  // namespace planet
#endif