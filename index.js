try {
  module.exports = require("./build/Release/tree_sitter_roll20_macro_binding");
} catch (error) {
  try {
    module.exports = require("./build/Debug/tree_sitter_roll20_macro_binding");
  } catch (_) {
    throw error
  }
}

try {
  module.exports.nodeTypeInfo = require("./src/node-types.json");
} catch (_) {}
