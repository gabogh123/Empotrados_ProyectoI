import { useState, useEffect } from 'react';
import axios from 'axios';


const useFetch = async (endpoint) => { 
    const [data, setData] = useState([]);
    const [isLoading, setIsLoading] = useState(false);
    const [error, setError] = useState(null);

    const options = {
        method: 'GET',
        url: `https://google-translate1.p.rapidapi.com/language/translate/v2/${endpoint}`,
        headers: {
            'Accept-Encoding': 'application/gzip',
            'X-RapidAPI-Key': rapidApiKey,
            'X-RapidAPI-Host': 'google-translate1.p.rapidapi.com'
        }
    };

    const fetchData = async () => {
        try {
            const response = await axios.request(options);
            console.log(response.data);
            setData(response.data.data);
            setIsLoading(false);
        } catch (error) {
            console.error(error);
            setError(error);
            alert('There is a fetching error');
        } finally {
            setIsLoading(false);
        }
    }

    useEffect(() => {
        fetchData();
    }, []);

    const refetch = () => {
        setIsLoading(true);
        fetchData();
    };

    return { data, isLoading, error, refetch };
}

export default useFetch;
