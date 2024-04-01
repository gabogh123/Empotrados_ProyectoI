import React from 'react';
import { FlatList, SafeAreaView, ScrollView, StyleSheet, Text, TouchableOpacity, View } from 'react-native';
import { Stack, useRouter } from 'expo-router';

import { COLORS, icons, images, SIZES } from '../../constants';

import DoorCard from './DoorCard';

const DoorsCard = () => {
	return (
	
        <View style={styles.container}>
            <View style={styles.header}>
                <Text style={styles.headerTitle}>Doors</Text>
                <Text style={styles.headerInfo}>Monitor-only state.</Text>
            </View>

            <View style={styles.containerCards}>
                <DoorCard/>
                <DoorCard/>
                <DoorCard/>
                <DoorCard/>
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
        marginTop: SIZES.medium,
    },
    header: {
        // flexDirection: "collumn",
        width: "100%",
		backgroundColor: COLORS.white,
        // paddingLeft: 20,
        paddingVertical: 20
    },
    headerTitle: {
        fontSize: SIZES.xLarge,
        color: COLORS.primary,
        marginBottom: 5,
      },
    headerInfo: {
        fontSize: SIZES.medium,
        color: COLORS.secondary,
      },
});

export default DoorsCard;
