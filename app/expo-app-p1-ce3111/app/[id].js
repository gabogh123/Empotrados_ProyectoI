import React from 'react';
import { Image, SafeAreaView, ScrollView, StyleSheet, Text, View } from 'react-native';
import { Stack, useRouter } from 'expo-router';

import { COLORS, icons, images, SIZES } from '../constants';

import HomeHeader from '../components/HomeHeader';
import HomeCard from '../components/HomeCard';

import homeLayoutImage from '../assets/images/home_layout.png';

const HomeScreen = () => {
	return (
		<SafeAreaView style={styles.containerMain}>
			<Stack.Screen
				options={{
					headerStyle: { backgroundColor: COLORS.white},
					headerShadowVisible: false,
					headerTitle: ""
				}}
			/>
			<ScrollView showsVerticalScrollIndicator={false}>
				<HomeHeader/>
				{/* Home Layout Image */}
				<View style={styles.containerImage}>
					<Image source={homeLayoutImage} style={styles.image} resizeMode="cover"/>
				</View>
				<Text style={styles.textInstructions}>Scroll down to control your home.</Text>
				<HomeCard/>
			</ScrollView>
		</SafeAreaView>
	);
};

const imgScl = 0.6;

const styles = StyleSheet.create({
	containerMain: {
		flex: 1,
		backgroundColor: COLORS.white,
	},
	homeCard: {
		padding: 10
	},
	containerImage: {
		// flex: 1,
        width: 498 * imgScl,
		height: 895 * imgScl,
        justifyContent: 'center',
        alignSelf: 'center',
		borderWidth: 3,
		borderColor: COLORS.gray,
		// padding: 20
    },
	image: {
        width: '100%', // Ocupa todo el ancho de su contenedor
        height: '100%', 
        // alignSelf: 'stretch', // Extiende la imagen horizontalmente
        resizeMode: 'contain', // Ajusta la imagen para cubrir todo el espacio
    },
	textInstructions: {
		justifyContent: 'center',
        alignSelf: 'center',
		paddingTop: 20
	}
});

export default HomeScreen;
