import React from 'react';
import { SafeAreaView, ScrollView, StyleSheet, Text, View } from 'react-native';
import { Stack, useRouter } from 'expo-router';

import { COLORS, icons, images, FONT, SIZES } from '../constants';

const HomeHeader = () => {
	return (
	
        <View style={styles.container}>
            <Text style={styles.textTitle}>Smart Home</Text>
            <Text style={styles.textProject}>Proyecto 1</Text>
        </View>
    
    );
};

const styles = StyleSheet.create({
	container: {
		width: "100%",
		backgroundColor: COLORS.white,
        paddingLeft: 20,
        paddingVertical: 20
	},
	textProject: {
        fontSize: SIZES.large,
        color: COLORS.secondary,
      },
    textTitle: {
        fontSize: SIZES.xLarge,
        color: COLORS.primary,
        marginTop: 2,
      },
});

export default HomeHeader;
