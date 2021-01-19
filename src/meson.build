src_files = files([
    'main.cpp',
    'Oscillator.cpp',
    'Gui.cpp',
    'GUI/Slider.cpp'
])

# ===== wxwidgets dependency =====

wxdep = dependency('wxwidgets', version: '>=3.0.0')

# ===== stk lib dependency =====

cc = meson.get_compiler('cpp')
stkdep = [
    cc.find_library('stk'),
    cc.find_library('rtaudio'),
    cc.find_library('asound'),
    cc.find_library('pthread')
]