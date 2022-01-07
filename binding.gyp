{
  "targets": [
    {
      "target_name": "tree_sitter_roll20_script_binding",
      "include_dirs": [
        "<!(node -e \"require('nan')\")",
        "src",
      ],
      "sources": [
        "src/parser.c",
        "bindings/node/binding.cc",
        #"src/scanner.cc",
      ],
      "cflags_c": [
        "-std=c99",
      ]
    }
  ]
}
