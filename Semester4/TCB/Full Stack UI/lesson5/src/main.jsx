import { StrictMode } from 'react'
import { createRoot } from 'react-dom/client'
import './index.css'
import App from './App.jsx'
import Card from './components/ColorCards.jsx';
import Page from './components/Page.jsx';
import BMICalc from './components/BMICalc.jsx';

createRoot(document.getElementById('root')).render(
  <StrictMode>
    {/* <App /> */}
    {/* <Card 
    name="tal"/> */}
    {/* <Page /> */}
    <BMICalc />
  </StrictMode>,
)
