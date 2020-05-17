# hello-ppx-esy

![](https://github.com/jchavarri/hello-ppx-esy/workflows/ppx_42%20pipeline/badge.svg)

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

## Files and folders

The example contains a couple of different targets that will be handled by dune (an OCaml build system)
to use the ppx in different projects:

- The library: located under `lib` folder. It is used directly by native projects, and indirectly by BuckleScript projects
- The standalone binary: BuckleScript does not provide a way to compose multiple ppxs together, so each ppx gets called individually, getting a serialized version of the AST, using the `-ppx` compiler flag behind the scenes. This can be configured in BuckleScript projects by using the `ppx-flags` key in `bsconfig.json` (see "Examples" section below).

For this reason, `ppx_42` exposes an executable that can be consumed by BuckleScript projects.

## Libraries used

#### `ocaml-migrate-parsetree`

[`ocaml-migrate-parsetree`](https://github.com/ocaml-ppx/ocaml-migrate-parsetree/) allows to transform between different
versions of OCaml ASTs (abstract syntax tree). This enables the ppx to work with even future versions of the compiler,
both in BuckleScript and in native.

For more information about this, check this post by @aantron: https://reasonml.chat/t/ppx-no-need-for-separate-ppx-and-ppx6-with-ocaml-migrate-parsetree-1-6-0/2210.

#### metaquot

[`metaquot`](https://github.com/ocaml-ppx/ppx_tools_versioned) is a ppx for ppxs :boom:.

It has many use cases, but the main one is that it allows to create new AST nodes just by using plain syntax.

So instead of writing:

```reason
Ast_helper.Exp.constant(Pconst_integer("42", None));
```

One can write:

```reason
[%expr 42];
```

The metaquot ppx will take care of "expanding" the literal into the fully fleshed AST node. To know more:
https://ppxlib.readthedocs.io/en/latest/ppx-for-plugin-authors.html.


## Examples

The repo contains a couple of demo examples that show one way to consume the ppx from both BuckleScript and native environments.

Check the readmes on each example folder:

- [BuckleScript](test_bs/README.md)
- [Native](test_native/README.md)
