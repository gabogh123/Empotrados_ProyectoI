import { useState } from 'react';
import { Alert, View, Image, SafeAreaView, StyleSheet, Text, TextInput } from 'react-native';
import { Stack, useRouter } from 'expo-router';

import { COLORS, icons, images, SIZES } from '../constants';

import meet from '../assets/images/meet_gabo_ruben.png';

import SignInButton from '../components/SignInButton';



const LogInScreen = () => {
    const router = useRouter(); // Obtén el objeto de enrutamiento

    const [isLoggedIn, setIsLoggedIn] = useState(false); // Estado para almacenar si el usuario está conectado

    const handleLogin = () => {
        // Aquí llamas a tu función de inicio de sesión
        // Supongamos que loginFunction() es la función que realiza el inicio de sesión
        const loginSuccessful = true;//loginFunction(); // Suponiendo que esta función devuelve true si el inicio de sesión es exitoso
        
        return loginSuccessful;
    };

    const logIn = () => {
        // Simulamos el inicio de sesión con un valor booleano aleatorio

        if (handleLogin()) {
            setIsLoggedIn(true);
            // Aquí puedes navegar a la nueva ventana o realizar cualquier acción deseada cuando el inicio de sesión sea exitoso
            console.log("log in succesfull");
            router.navigate('/home'); // Navega a la pantalla 'Home' después del inicio de sesión exitoso
          } else {
            Alert.alert('Error', 'Log in failed');
            console.log("log in failed");
          }
      };



    return (
        <SafeAreaView style={styles.containerMain}>
            <Stack.Screen
                options={{
                    headerStyle: { backgroundColor: COLORS.white}, headerShadowVisible: false,
                    headerTitle: ""
                }}
            />
            {/* Image */}
            {/* <View style={styles.containerImage}>
                <Image source={meet} style={styles.image} resizeMode="cover"/>
            </View> */}
            {/* Texts */}
            <View style={styles.containerText}>
                <Text style={styles.title}>Smart Home</Text>
                <Text style={styles.subtitle}>Sign in to your account</Text>
                <TextInput
                    placeholder="beto@email.com"
                    style={styles.textInput}
                    />
                <TextInput
                    placeholder="password"
                    style={styles.textInput}
                    secureTextEntry={true}
                />
                <Text style={styles.textForgot}>Please don't forget your password</Text>
                {/* Button */}
                <View style={styles.containerButton}>
                    <SignInButton
                        buttonFunction={logIn}
                        text={"Log In"}
                    />
                </View>
                <Text style={styles.textLast}>CE1113 - Sistemas Empotrados</Text>
            </View>


        </SafeAreaView>
    )
}

const styles = StyleSheet.create({
    containerMain: {
      flex: 1,
      backgroundColor: COLORS.white,
    //   alignItems: 'center',
    //   justifyContent: 'center'
    },
    containerButton: {
        width: "100%",
        display: "flex",
        alignItems: "center",
        marginTop: 60,
    },
    containerImage: {
        width: '100%',
        justifyContent: 'flex-start',
        alignItems: 'center'
    },
    containerText: {
        flex: 1,
        backgroundColor: COLORS.white,
        alignItems: 'center',
        justifyContent: 'center'
    },  
    image: {
        width: '100%', // Ocupa todo el ancho de su contenedor
        height: 200, 
        alignSelf: 'stretch', // Extiende la imagen horizontalmente
        resizeMode: 'cover', // Ajusta la imagen para cubrir todo el espacio
      },
    subtitle: {
        fontSize: 20,
        color: COLORS.gray
    },
    textForgot: {
        fontSize: 14,
        color: COLORS.gray,
        padding: 10,
        marginTop: 20,
    },
    textInput: {
        padding: 10,
        paddingStart: 30,
        width: '80%',
        height: 50,
        marginTop: 20,
        borderRadius: 30,
        backgroundColor: COLORS.lightWhite
    },
    textLast: {
        fontSize: 14,
        color: COLORS.gray,
        padding: 10,
        marginTop: 20,
    },
    title: {
        fontSize: 80,
        color: COLORS.lightBlack,
        fontWeight: 'bold'
    }
  });

export default LogInScreen;
