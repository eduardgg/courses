import {useParams} from 'react-router-dom';
export default function Profile() {
    const {name} = useParams();
    console.log(name)
    return (
        <div>
            <p>Des de Profile, amb el nom {name}</p>
        </div>
    )
}