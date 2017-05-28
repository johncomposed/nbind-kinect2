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
          "./node_modules/nbind/src/nbind.gypi",
      ],
      "include_dirs": [
        "./node_modules/nan"
      ],
      "conditions": [
        ['OS=="mac"', {
          "include_dirs": ["/usr/local/include"],
          "library_dirs": ["/usr/local/lib"],
        }],
      ]
    }
  ],

  "includes": [
    "./node_modules/nbind/src/nbind-common.gypi"
  ]
}
