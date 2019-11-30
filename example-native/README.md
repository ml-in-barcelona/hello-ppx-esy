You can see an example of usage in a native project in this folder.

The most relevant point is the `(preprocess (pps my_ppx_lib))` stanza in `dune` file, that is pointing to the ppx library.

To compile the example, run from this folder:

    % esy install

Then you can run

    % esy build

At that point, you can run `esy x my_native_app.exe` from the command line, you should see `42` being printed.
