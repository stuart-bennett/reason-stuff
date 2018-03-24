type playlist = {
    id: string,
    name: string
};

let component = ReasonReact.statelessComponent("Playlists");
let fn = (i: playlist) => {
    <li key=i.id>
        { ReasonReact.stringToElement(i.name) }
    </li>;
};

let make = (~playlists: list(playlist), _children) => {
    ...component,
    render: (_self) => {
        <div>
            <h1>{ReasonReact.stringToElement("Your Playlists")}</h1>
            <ul>
                {List.map(fn, playlists) |> Array.of_list |> ReasonReact.arrayToElement}
            </ul>
            <button className="btn btn-primary">
                {ReasonReact.stringToElement("Add new...")}
            </button>
        </div>;
    }
};
