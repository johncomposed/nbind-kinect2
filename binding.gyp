{
  "targets": [
    {
      "sources": [
        "./src/kinect.cc",
      ],
      "libraries": [
         "libfreenect2.a",
      ],
      "includes": [
        "./auto.gypi"
      ],
      "conditions": [
        ['OS=="mac"', {
          "include_dirs": ["/usr/local/include"],
          "library_dirs": ["/usr/local/lib"],
          "xcode_settings": {
            "OTHER_CPLUSPLUSFLAGS": [
              "-frtti"
            ]
          }
        }],
      ]
    }
  ],

  "includes": [
    "./auto-top.gypi"
  ]
}
