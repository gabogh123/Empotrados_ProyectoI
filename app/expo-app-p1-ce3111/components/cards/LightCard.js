import React from 'react';
import { FlatList, SafeAreaView, ScrollView, StyleSheet, Text, TouchableOpacity, View } from 'react-native';
import { Stack, useRouter } from 'expo-router';

import { COLORS, icons, images, SIZES } from '../../constants';

const LightCard = ( item, ) => {
	return (
	
        <View style={styles.container}>
            <View style={styles.header}>
                <Text style={styles.headerTitle}>One light</Text>
            </View>
        </View>
    
    );
};

const styles = StyleSheet.create({
    container: {
        marginTop: 10,
        marginBottom: 10
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
    cardsContainer: {
        marginTop: SIZES.medium,
    },
});

export default LightCard;
