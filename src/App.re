module Styles = {
  open Css;
  let page = style([
    width @@ px(1024),
    marginLeft @@ auto,
    marginRight @@ auto
  ]);
  let title = style([
    fontFamily @@ "Montserrat, sans-serif",
    fontSize @@ px(24),
    fontWeight @@ 300
  ])
};

type state = {
  title: string
};

type msg =
  | SetTitle(string);

let component = ReasonReact.reducerComponent("App");
let make = (_) => {
  ...component,
  initialState: () => {title: "React Boilerplate"},
  reducer: (msg, state) => {
    open ReasonReact;
    switch msg {
      | SetTitle(title) => Update({...state, title});
    }
  },
  render: ({state, send}) => {
    let onChange = e => send(SetTitle(ReactDOMRe.domElementToObj(ReactEventRe.Form.target(e))##value));
    <div className=Styles.page>
      <h1 className=Styles.title> (ReasonReact.string(state.title)) </h1>
      <input value=state.title onChange/>
    </div>
  }
};
