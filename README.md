# hello-ppx-esy

A project that includes the minimum configuration for a [ppx](https://blog.hackages.io/reasonml-ppx-8ecd663d5640) called `ppx_42`, a project that uses Reason and [Esy](https://github.com/esy-ocaml/esy).

`ppx_42` implements a very basic ppx that transforms the `[%gimme]` extension into the number literal `42`.

So, the code:

```reason
let fourtyTwo = string_of_int([%gimme]);
```

Is transformed into:

```reason
let fourtyTwo = string_of_int(42);
```

## Usage

You need Esy, you can install the beta using [npm](https://nodejs.org/en/download/):

    % npm install -g esy@latest

Then you can install the project dependencies using:

    % esy install

Then build the project dependencies along with the project itself:

    % esy build

After building, you should see an executable in `_esy/default/build/default/.ppx/ppx_42/ppx.exe`.
This will be the binary used by BuckleScript in the example below.

## Examples

The repo contains a couple of demo examples that show one way to consume the ppx from both BuckleScript and native environments.

Check the readmes on each folder to read information about them:

- [BuckleScript example](example-bs/README.md)
- [Native example](example-native/README.md)
