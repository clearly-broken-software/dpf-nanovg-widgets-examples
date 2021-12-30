# CMake file for DISTRHO Plugins # ------------------------------ #
cmake_minimum_required(VERSION 3.10)
project(nanovg_widgets_example)
add_subdirectory(DPF)

dpf_add_plugin(nanovg_widgets_example
  TARGETS jack lv2 vst2
  FILES_DSP
    NanovgWidgetsExamplePlugin.cpp
  FILES_UI
    NanovgWidgetsExampleUI.cpp
    widgets/src/Button.cpp
    widgets/src/Knob.cpp
    widgets/src/Slider.cpp
    widgets/src/Spinner.cpp
    widgets/src/Switch.cpp

    dpf-nanovg-widgets/src/ExtraEventHandlers.cpp
    dpf-nanovg-widgets/src/NanoButton.cpp
    dpf-nanovg-widgets/src/NanoKnob.cpp
    dpf-nanovg-widgets/src/NanoSlider.cpp
    dpf-nanovg-widgets/src/NanoSpinner.cpp
    dpf-nanovg-widgets/src/NanoSwitch.cpp
        )

target_include_directories(
  nanovg_widgets_example PUBLIC 
    "." 
    dpf-nanovg-widgets
    widgets
    )
