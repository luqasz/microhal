project(
        'microhal',
        'cpp',
        'c',
        default_options: [
            'buildtype=minsize',
            'optimization=s',
            'strip=true',
            'cpp_std=c++17',
            'b_lto=true',
            'warning_level=3',
            'werror=true',
            ]
        )

add_project_arguments(
        '-Wconversion',
        '-Wsign-conversion',
        '-Wfloat-conversion',
        '-fno-asynchronous-unwind-tables',
        language: ['cpp', 'c'],
        )

add_project_arguments(
        '-Woverloaded-virtual',
        '-fno-exceptions',
        '-fno-rtti',
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
  'ws2812',
  'lcd',
  'pin_irq',
  'pwm',
]

if meson.is_cross_build()
  add_project_arguments(
        '-fmerge-constants',
        '-ffunction-sections',
        '-fdata-sections',
        language: ['cpp', 'c'],
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
      include_directories : [
        include_directories('src/atmega32'),
        src_dir
      ]
  )
endif

