import React from 'react';
import { SafeAreaView, ScrollView, StyleSheet, Text, View } from 'react-native';
import { Stack, useRouter } from 'expo-router';

import { COLORS, icons, images, SIZES } from '../constants';

const HomeScreen = () => {
	return (
		<SafeAreaView style={styles.containerMain}>
			<Stack.Screen
				options={{
					headerStyle: { backgroundColor: COLORS.white}, headerShadowVisible: false,
					headerTitle: ""
				}}
			/>

			<Text>HomeScreen</Text>
		</SafeAreaView>
	);
};

const styles = StyleSheet.create({
	containerMain: {
		flex: 1,
		backgroundColor: COLORS.white,
	},
	containerButton: {
		width: "100%",
		display: "flex",
		alignItems: "center",
		marginTop: 60,
	}
});

export default HomeScreen;
