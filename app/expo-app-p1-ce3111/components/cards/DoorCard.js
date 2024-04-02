import React from 'react';
import { StyleSheet, Text, View } from 'react-native';
import { COLORS, SIZES } from '../../constants';


const DoorCard = ( {item, ubication, state} ) => {

	return (
        <View style={styles.container}>
            <View style={styles.texts}>
                <Text style={styles.element}>{`${item.controlElement} ${item.id}`}</Text>
                <Text style={styles.state}>{item.state}</Text>
            </View>
        </View>
    );
};

const styles = StyleSheet.create({
    container: {
        marginTop: 10,
        marginBottom: 10
    },
    texts: {
        flexDirection: "collumn",
        justifyContent: "space-between",
        alignItems: "flex-start",
        marginHorizontal: 30
    },
    element: {
        fontSize: SIZES.large,
        color: COLORS.primary,
    },
    state: {
        fontSize: SIZES.medium,
        color: COLORS.secondary,
    },
    cardsContainer: {
        marginTop: SIZES.medium,
    },
});

export default DoorCard;
