project(
        'microhal',
        'cpp',
        'c',
        default_options: [
            'buildtype=minsize',
            'optimization=s',
            'strip=true',
            'cpp_std=c++17',
            'b_lto=false',
            'warning_level=3',
            'werror=true',
            ]
        )

cpp_compiler = meson.get_compiler('cpp')

# clang doesn't have this option
if cpp_compiler.has_argument('-fsingle-precision-constant')
add_project_arguments(
        '-fsingle-precision-constant',
        language: ['cpp', 'c'],
        )
endif

add_project_arguments(
        '-Wpadded',
        '-Wconversion',
        '-Wsign-conversion',
        '-Wfloat-conversion',
        '-fno-asynchronous-unwind-tables',
        '-Wno-non-virtual-dtor',
        '-Wdouble-promotion',
        '-fno-short-enums',
        language: ['cpp', 'c'],
        )

add_project_arguments(
        '-Woverloaded-virtual',
        language: ['cpp'],
        )

src_dir = include_directories('src/')

examples = [
  'rtc',
  'usart',
  'flash',
  'adc',
  'spi',
  'watchdog',
  'lcd',
  'pin_irq',
  'pwm',
  'thermistor'
]

if meson.is_cross_build()
    add_project_arguments(
        '-fmerge-constants',
        '-ffunction-sections',
        '-fdata-sections',
        language: ['cpp', 'c'],
        )
    add_project_arguments(
        '-fno-exceptions',
        '-fno-rtti',
        language: ['cpp'],
        )
  add_project_link_arguments(
        '-Wl,--print-memory-usage',
        '-Wl,--gc-sections',
        '-ffunction-sections',
        '-fdata-sections',
        language: ['cpp', 'c'],
        )

  mcu_dir = include_directories('src/' + host_machine.cpu())

  foreach e : examples
    executable(
        e,
        'examples/@0@.cpp'.format(e),
        build_by_default: true,
        include_directories : [
          mcu_dir,
          src_dir
        ]
    )
  endforeach

endif

if not meson.is_cross_build()

  executable(
      'tests',
      'tests/ubrr.cpp',
      'tests/tests_main.cpp',
      'tests/thermistor.cpp',
      'tests/vdiv.cpp',
      include_directories : [
        include_directories('src/atmega32'),
        src_dir
      ]
  )
endif

