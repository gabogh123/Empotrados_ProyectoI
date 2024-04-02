import React from 'react';
import { StyleSheet, View } from 'react-native';
import { COLORS, SIZES } from '../constants';

import Lights from './Lights';
import Doors from './Doors';
import PictureCard from './cards/PictureCard';


const HomeCard = ( {url}) => {


	return (
	
        <View style={styles.container}>
            <Lights url={url}/>
            <Doors url={url}/>
            <PictureCard url={url}/>
        </View>
    
    );
};

const styles = StyleSheet.create({
    container: {
        marginTop: SIZES.xLarge,
        flex: 1,
        flexDirection: 'collumn', // Para que los elementos se distribuyan horizontalmente
        justifyContent: 'space-between', // Distribuye el espacio entre los elementos de manera uniforme
        paddingHorizontal: 20, // Ajusta el espaciado horizontal del contenedor,
    },
    header: {
        flexDirection: "row",
        justifyContent: "space-between",
        alignItems: "center",
    },
    headerTitle: {
        fontSize: SIZES.large,
        color: COLORS.primary,
    },
    headerBtn: {
        fontSize: SIZES.medium,
        color: COLORS.gray,
    },
    cardsContainer: {
        marginTop: SIZES.medium,
    },
});

export default HomeCard;
