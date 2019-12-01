# Using `ppx_42`: Native example

You can see an example of usage in a native project in this folder.

The most relevant point is the `(preprocess (pps ppx_42.lib))` stanza in `dune` file, that is pointing to the ppx library.

To compile the example, run from this folder:

```bash
$ esy install
```

Then you can run:

```bash
$ esy build
```

At that point, executing `esy x my_native_app.exe` from the command line should print `42` in the standard output.
