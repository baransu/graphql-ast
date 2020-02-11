open TestFramework;
open GraphQL;

let rewrite_query = (query, ()) => {
  let lexer = Graphql_lexer.make(query);

  switch (Graphql_lexer.consume(lexer)) {
  | Result.Error(e) => failwith("lexer error")
  | Result.Ok(tokens) =>
    let parser = Graphql_parser.make(tokens);
    switch (Graphql_parser_document.parse_document(parser)) {
    | Result.Error(e) => failwith("parse error")
    | Result.Ok(document) => document
    };
  };
};

let get_operation_name = operation => {
  SourcePos.(
    Graphql_ast.(operation.item.o_name |> Option.map(o_name => o_name.item))
  );
};

describe("my first test suite", ({test, _}) => {
  test("1 + 1 should equal 2", ({expect, _}) => {
    let result =
      rewrite_query(
        {|
      query A {
        a {
          b {
            c
          }
        }
      }
    |},
        (),
      );

    switch (result) {
    | [Graphql_ast.Operation(operation)] =>
      let name = get_operation_name(operation) |> Option.unsafe_unwrap;
      expect.string(name).toEqual("A");
    | _ => failwith("Invalid number of operations")
    };
  })
});
