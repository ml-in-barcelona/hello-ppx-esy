open Migrate_parsetree;
let mapper = (_, _) =>
  Ast_408.(
    Ast_mapper.(
      Parsetree.(
        Asttypes.{
          ...default_mapper,
          expr: (mapper, e) => {
            switch (e.pexp_desc) {
            /* If the expression is [%gimme] */
            | Pexp_extension(({txt: "gimme", _}, _payload)) =>
              /* Then replace by 42 */
              %expr
              42
            | _ => default_mapper.expr(mapper, e)
            };
          },
        }
      )
    )
  );

let () =
  Migrate_parsetree.(
    Driver.register(~name="ppx_42", Versions.ocaml_408, mapper)
  );
