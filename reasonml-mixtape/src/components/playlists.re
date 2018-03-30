type playlist = {
    id: string,
    name: string
};
type response = {
    data: array(playlist)
};

type state = {
    playlists: list(playlist)
};

let component = ReasonReact.reducerComponent("Playlists");
let fn = (p: playlist) => {
    <li key=p.id>
        { ReasonReact.stringToElement(p.name) }
    </li>;
};

let headers: array((string, string)) = [|
    ("Authorization", "Bearer BQBeTpKxwzgUpfVmVhDmRcJD9nuQ0F4ch_BQ3kz7q7wD90FkEPzHu3gZhaCcuFAAf9VGnGwDaLDGICj3WUOfZXnr6-BFKLX4HyZJBXNCJCbF-cfWpIUpI1Cf2VZTdWDY598wTYDybolHSfAbmLr2nQkDZC2DNc8RqheKkwSMnlhe")
|];

module Decode = {
    let playlist = json =>
        Json.Decode.{
            id: json |> field("ids", string),
            name: json |> field("name", string)
        };

    let response = json =>
        Json.Decode.{
            data: json |> field("items", array(playlist))
        };
};

let playlists = Js.Promise.(
    Fetch.fetchWithInit(
        "https://api.spotify.com/v1/me/playlists",
        Fetch.RequestInit.make(~headers=Fetch.HeadersInit.makeWithArray(headers),()))
    |> then_(Fetch.Response.json)
    |> then_((json) => {
        switch (json |> Decode.response) {
        | value => Js.log(value.data)
        | exception msg => Js.log(msg)
        };
        Js.Promise.resolve();
    })
);

let make = (_children) => {
    ...component,
    initialState: () => {
        playlists: []
    },
    reducer: ((), _: state) => ReasonReact.NoUpdate,
    render: (self) => {
        <div>
            <h1>{ ReasonReact.stringToElement("Your Playlists") }</h1>
            <ul>
                {  List.map(fn, self.state.playlists)
                |> Array.of_list
                |> ReasonReact.arrayToElement }
            </ul>
            <button className="btn btn-primary">
                { ReasonReact.stringToElement("Add new...") }
            </button>
        </div>;
    }
};
