import { 
    ActivityIndicator, StyleSheet, Text, TouchableOpacity, View 
} from 'react-native';
import { useRouter } from 'expo-router';

import { COLORS } from '../constants';
import LightCard from './cards/LightCard';

import useGet from '../hook/useGet';
import useFetch from '../hook/useFetch';

const Lights = () => {
    const router = useRouter();

    const { data, isLoading, error } = useGet(
		// 'http://192.168.50.180:8888', 'encenderluz4'
		'http://172.20.10.2:8888', 'encenderluz4'
	);

    


	return (
	
        <View style={styles.container}>
            <View style={styles.header}>
                <Text style={styles.headerTitle}>Lights</Text>
                <Text style={styles.headerInfo}>Press each to change state.</Text>
            </View>

            <View style={styles.containerCards}>
                <LightCard ubication='Cuarto 1'/>
                <LightCard ubication='Cuarto 2'/>
                <LightCard ubication='Sala'/>
                <LightCard ubication='Comedor'/>
                <LightCard ubication='Cocina'/>
            </View>
        </View>
    
    );
};

const styles = StyleSheet.create({
    container: {
        marginTop: 10,
        marginBottom: 10
    },
    containerCards: {

    },
    header: {
        width: "100%",
		backgroundColor: COLORS.white,
        // paddingLeft: 20,
        paddingVertical: 20
    },
    headerTitle: {

        color: COLORS.primary,
        marginBottom: 5,
      },
    headerInfo: {

        color: COLORS.secondary,
      },
});

export default Lights;
