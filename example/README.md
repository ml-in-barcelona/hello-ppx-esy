# Example project with ppx_bs_css + esy

## Why

One of the most promising ongoing projects in the Reason platform is [`ppx_bs_css`](https://github.com/astrada/ppx_bs_css/issues/3) by @astrada, which allows to use CSS syntax from Reason / OCaml and compiles down to functions exposed by CSS libraries like [`bs-typed-glamor`](https://github.com/glennsl/bs-typed-glamor) or [`bs-css`](https://github.com/SentiaAnalytics/bs-css).

Consuming ppxs is generally not trivial though, as it involves either native compilation or distribution of platform binaries. [Note: if you come from JavaScript, you can think of PPXs as Babel plugins. You can read more about what a PPX is in [this article](https://blog.hackages.io/reasonml-ppx-8ecd663d5640)].

`esy` to the rescue! With [`esy`](https://esy.sh/), a package manager for Reason / OCaml, it's possible to consume PPXs by using a regular `package.json` file, in a very similar way than with npm / yarn. And then `esy` takes care of compiling the ppx so the binary can be used during the compilation step of your project.

## What

This project is a variation of the ReasonReact template included with BuckleScript (the one that you get by running `bsb -init my-react-app -theme react`) with the following additions:

- `ppx_bs_css`
- `bs-typed-glamor`

The main goal is to enable the experimentation with `ppx_bs_css` without letting the configuration get in the way.

## Global Dependencies

- [Reason toolchain](https://reasonml.github.io/docs/en/global-installation.html)
- Esy: `npm install -g esy@preview`


## Install Project Dependencies

```sh
esy install
esy build
ln -s $(esy which bs-ppx-css) bs-ppx-css
```

## Run Project Dependencies

```sh
yarn run start
# in another tab
yarn run webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `src/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

## `[%style]` and `[%css]` extension points

The first allows to define only a set of CSS properties, while the second works in "stylesheet mode", allowing to group CSS properties with selectors.

## Can expressions be used inside the styles?

There is currently no way to add things like JavaScript template literals. But identifiers can be used inside the styles, so something like this is possible:

```reason
let className = (active) => {
  let bkg = active ? red : blue;
  TypedGlamor.(
    [%style
      {typed|
        background-color: bkg;
      |typed}
    ]
    |. css
    |. toString
  );
}
```

## Build for Production

```sh
npm run build
npm run webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
