const path = require('path');

module.exports = {
  entry: './lib/js/src/Main.js',
  output: {
    path: path.join(__dirname, "public"),
    filename: 'bundle.js',
  },
  devServer: {
    historyApiFallback: {
      index: 'index.html'
    },
    contentBase: 'public/',
    inline: true,
    port: 1234
  }
};
