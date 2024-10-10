import {useState, useEffect} from 'react';

export default function Welcome(props) {
    console.log(props);
    const [counter, setCounter] = useState(0);
    const [semafor, setSemafor] = useState(false);
    const {message, name} = props;
    
    useEffect(() => {
        // S'executa quan "semafor" canvia
        console.log(semafor);
    }, [semafor])


    const contar = () => {
        console.log("Entrant en la funció de comptar.")
        setCounter(counter + 1);
        setSemafor(!semafor)
    }
    return (
        <div>
            <h1>Bon dia, {name}</h1>
            <p>{message}</p>
            <h2>Comptador de React amb Hooks</h2>
            <h4>El nombre del comptador és {counter}</h4>
            <p>El semàfor està en color {semafor ? "red" : "green"}</p>
            <button type="submit" onClick={contar}>
                Sumar comptador
            </button>
        </div>
    );
}