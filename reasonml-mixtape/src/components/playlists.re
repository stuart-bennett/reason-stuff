type playlist = {
    id: string,
    name: string
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

let make = (_children) => {
    ...component,
    initialState: () => {
        playlists: [
        {
            id: "001",
            name: "Number #1"
        },
        {
            id: "002",
            name: "Number #2"
        }]
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
