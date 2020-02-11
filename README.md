# graphql-ast


[![CircleCI](https://circleci.com/gh/yourgithubhandle/graphql-ast/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/graphql-ast/tree/master)


**Contains the following libraries and executables:**

```
graphql-ast@0.0.0
│
├─test/
│   name:    TestGraphqlAst.exe
│   main:    TestGraphqlAst
│   require: graphql-ast.lib
│
├─library/
│   library name: graphql-ast.lib
│   namespace:    GraphqlAst
│   require:
│
└─executable/
    name:    GraphqlAstApp.exe
    main:    GraphqlAstApp
    require: graphql-ast.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x GraphqlAstApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
