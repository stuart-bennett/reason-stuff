let component = ReasonReact.statelessComponent("App");

type oAuthSettings = {
    baseUri: string,
    clientId: string,
    redirectUri: string
};

let oAuthSettings = {
    baseUri: "https://accounts.spotify.com/authorize/",
    clientId: "1f662e1ad1ae494382cd56133ebb7b14",
    redirectUri: "http://localhost:8080/index.html"
};

let makeOAuthUrl = ({ baseUri, clientId, redirectUri }) => baseUri ++
    "?client_id=" ++ clientId ++
    "&response_type=token" ++
    "&scope=playlist-modify-public" ++
    "&redirect_uri=" ++ redirectUri;

let make = (_children) => {
    ...component,
    render: (self) => {
        <div>
            <a href={ makeOAuthUrl(oAuthSettings) }>{ ReasonReact.stringToElement("Authorise") }</a>
        </div>
    }
};
