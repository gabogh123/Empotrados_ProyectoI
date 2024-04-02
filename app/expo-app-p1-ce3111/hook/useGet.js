import { useState, useEffect } from 'react';
import axios from 'axios';

const testHtml2 = '<html><body><h1>Luz 1</h1><p>Estado: EncendidaT</p><form method="post" action="/encenderluz1"><input type="submit" value="Encender Luz 1"></form><form method="post" action="/apagarluz1"><input type="submit" value="Apagar Luz 1"></form><h1>Luz 2</h1><p>Estado: Apagada</p><form method="post" action="/encenderluz2"><input type="submit" value="Encender Luz 2"></form><form method="post" action="/apagarluz2"><input type="submit" value="Apagar Luz 2"></form><h1>Luz 3</h1><p>Estado: EncendidaT</p><form method="post" action="/encenderluz3"><input type="submit" value="Encender Luz 3"></form><form method="post" action="/apagarluz3"><input type="submit" value="Apagar Luz 3"></form><h1>Luz 4</h1><p>Estado: EncendidaT</p><form method="post" action="/encenderluz4"><input type="submit" value="Encender Luz 4"></form><form method="post" action="/apagarluz4"><input type="submit" value="Apagar Luz 4"></form><h1>Luz 5</h1><p>Estado: EncendidaT</p><form method="post" action="/encenderluz5"><input type="submit" value="Encender Luz 5"></form><form method="post" action="/apagarluz5"><input type="submit" value="Apagar Luz 5"></form><h1>Capturar Imagen</h1><form method="post" action="/capturarimagen"><input type="submit" value="Capturar"></form></body></html>';
const testHtml1 = '<html><body><h1>Luz 1</h1><p>Estado: Apagada</p><form method="post" action="/encenderluz1"><input type="submit" value="Encender Luz 1"></form><form method="post" action="/apagarluz1"><input type="submit" value="Apagar Luz 1"></form><h1>Luz 2</h1><p>Estado: Apagada</p><form method="post" action="/encenderluz2"><input type="submit" value="Encender Luz 2"></form><form method="post" action="/apagarluz2"><input type="submit" value="Apagar Luz 2"></form><h1>Luz 3</h1><p>Estado: Apagada</p><form method="post" action="/encenderluz3"><input type="submit" value="Encender Luz 3"></form><form method="post" action="/apagarluz3"><input type="submit" value="Apagar Luz 3"></form><h1>Luz 4</h1><p>Estado: Apagada</p><form method="post" action="/encenderluz4"><input type="submit" value="Encender Luz 4"></form><form method="post" action="/apagarluz4"><input type="submit" value="Apagar Luz 4"></form><h1>Luz 5</h1><p>Estado: Apagada</p><form method="post" action="/encenderluz5"><input type="submit" value="Encender Luz 5"></form><form method="post" action="/apagarluz5"><input type="submit" value="Apagar Luz 5"></form><h1>Capturar Imagen</h1><form method="post" action="/capturarimagen"><input type="submit" value="Capturar"></form></body></html>';

// Hook para realizar solicitudes GET
const useGet = (url, dynamicPath) => {
    const [data, setData] = useState(null);
    const [isLoading, setIsLoading] = useState(true);
    const [error, setError] = useState(null);

    const options = {
        method: 'GET',
        url: `${url}/${dynamicPath}`,
        headers: {
            'Accept-Encoding': 'application/gzip'
        }
    };

    const fetchData = async () => {
        try {
            // const response = await axios.request(options);
            // console.log(response.data);
            // console.log(typeof response.data);
            setIsLoading(true);
            
            // const htmlData = response.data;
            const htmlData = testHtml2;
            
            // Regular expression to match <h1> and <p> tags
            const regex = /<h1>(.*?) (.*?)<\/h1><p>Estado: (.*?)<\/p>/gs;

            // Array to store matched content
            const resultList = [];

            let match;
            while ((match = regex.exec(htmlData)) !== null) {
            const controlElement = match[1]; // Content of <h1> tag
            const id = match[2]; // Content of <p> tag
            const state = match[3]; // Content of <p> tag
            resultList.push({ controlElement, id,  state });
            }

            console.log(resultList);

            setData(resultList);

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
    }

    return { data, isLoading, error, refetch };
};

export default useGet;
