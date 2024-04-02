import { useState } from 'react';
import axios from 'axios';
// import { API_URL } from '@env';

// Hook para realizar solicitudes POST
const usePost = (url, dynamicPath) => {
  const [response, setResponse] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);

  const postData = async (url, dynamicPath, postData) => {
    setLoading(true);
    try {
      const response = await axios.post(`${url}/${dynamicPath}`, postData);
      setResponse(response.data);
      setLoading(false);
      console.log(response.status, response.data);
    } catch (error) {
      setError(error);
      setLoading(false);
      console.log(error);
    }
  };

  return { response, loading, error, postData };
};

export default usePost;
