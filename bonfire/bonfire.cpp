//
//
// bonfire.cpp
// Author: Yuchen Cheng <rudeigerc@gmail.com>
//
//
  
 # i n c l u d e   " w i n d o w s . h " 
 # i n c l u d e   " s t d l i b . h "  
 # d e f i n e   G L U T _ D I S A B L E _ A T E X I T _ H A C K  
 # i n c l u d e   < g l / g l u t . h >  
 # i n c l u d e   < i o s t r e a m >  
 # i n c l u d e   < v e c t o r >  
 # i n c l u d e   " c o n f i g . h "  
 # i n c l u d e   " c a m e r a . h "  
 # i n c l u d e   " p a r t i c l e . h "  
 # i n c l u d e   " t e x t u r e _ l o a d e r . h "  
 # i n c l u d e   " o b j _ l o a d e r . h "  
  
 s t d : : v e c t o r < P a r t i c l e >   p a r t i c l e s ;  
 C a m e r a   c a m e r a ;  
 O b j L o a d e r   l o a d e r ;  
  
 v o i d   d i s p l a y ( )   {  
 	 g l C l e a r ( G L _ C O L O R _ B U F F E R _ B I T   |   G L _ D E P T H _ B U F F E R _ B I T ) ;  
 	 g l M a t r i x M o d e ( G L _ M O D E L V I E W ) ;  
 	 g l L o a d I d e n t i t y ( ) ;  
 	  
 	 f o r   ( P a r t i c l e   & p a r t i c l e   :   p a r t i c l e s )   {  
 	 	 p a r t i c l e . d i s p l a y ( l o a d e r ,   d e l t a _ r e d _ o f _ f i r e ) ;  
 	 }  
 	  
 	 g l u t S w a p B u f f e r s ( ) ;  
 }  
  
 v o i d   i d l e ( )   {  
 	 d i s p l a y ( ) ;  
 }  
  
 v o i d   r e s h a p e ( i n t   w ,   i n t   h )   {  
 	 g l V i e w p o r t ( 0 ,   0 ,   ( G L s i z e i ) w ,   ( G L s i z e i ) h ) ;  
 	 g l M a t r i x M o d e ( G L _ P R O J E C T I O N ) ;  
 	 g l L o a d I d e n t i t y ( ) ;  
 	 g l u P e r s p e c t i v e ( 4 5 . 0 f ,   ( G L f l o a t ) w   /   ( G L f l o a t ) h ,   0 . 1 f ,   2 0 0 . 0 f ) ;  
 	 g l u L o o k A t ( 0 . 0 ,   0 . 0 ,   5 . 0 ,   0 . 0 ,   1 . 5 ,   0 . 0 ,   0 . 0 ,   1 . 0 ,   0 . 0 ) ;  
 }  
  
 v o i d   k e y b o a r d ( u n s i g n e d   c h a r   k e y ,   i n t   x ,   i n t   y )   {  
 	 s w i t c h   ( k e y )   {  
 	 c a s e   K E Y _ E S C :  
 	 	 e x i t ( 0 ) ;  
 	 	 b r e a k ;  
 	 c a s e   K E Y _ S P A C E :  
 	 	 d e l t a _ r e d _ o f _ f i r e   =   0 . 0 f ;  
 	 	 w h i l e   ( p a r t i c l e s . s i z e ( )   <   m a x _ p a r t i c l e )   {  
 	 	 	 p a r t i c l e s . p u s h _ b a c k ( P a r t i c l e ( ) ) ;  
 	 	 }  
 	 	 b r e a k ;  
 	 c a s e   ' m ' :  
 	 	 d e l t a _ r e d _ o f _ f i r e   + =   d e l t a _ c o l o r _ s t e p ;  
 	 	 b r e a k ;  
 	 c a s e   ' n ' :  
 	 	 d e l t a _ r e d _ o f _ f i r e   - =   d e l t a _ c o l o r _ s t e p ;  
 	 	 b r e a k ;  
 	 c a s e   ' w ' :  
 	 	 c a m e r a . m o v e F o r w a r d ( ) ;  
 	 	 b r e a k ;  
 	 c a s e   ' a ' :  
 	 	 c a m e r a . r o t a t e L e f t ( ) ;  
 	 	 b r e a k ;  
 	 c a s e   ' s ' :  
 	 	 c a m e r a . m o v e B a c k w a r d ( ) ;  
 	 	 b r e a k ;  
 	 c a s e   ' d ' :  
 	 	 c a m e r a . r o t a t e R i g h t ( ) ;  
 	 	 b r e a k ;  
 	 c a s e   ' q ' :  
 	 	 c a m e r a . m o v e U p ( ) ;  
 	 	 b r e a k ;  
 	 c a s e   ' e ' :  
 	 	 c a m e r a . m o v e D o w n ( ) ;  
 	 	 b r e a k ;  
 	 c a s e   ' - ' :  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   p a r t i c l e _ s t e p ;   i + + )   {  
 	 	 	 i f   ( p a r t i c l e s . s i z e ( )   >   m i n _ p a r t i c l e )   {  
 	 	 	 	 p a r t i c l e s . p o p _ b a c k ( ) ;  
 	 	 	 }  
 	 	 }  
 	 	 b r e a k ;  
 	 c a s e   ' = ' :  
 	 	 f o r   ( i n t   i   =   0 ;   i   <   p a r t i c l e _ s t e p ;   i + + )   {  
 	 	 	 i f   ( p a r t i c l e s . s i z e ( )   <   m a x _ p a r t i c l e )   {  
 	 	 	 	 p a r t i c l e s . p u s h _ b a c k ( P a r t i c l e ( ) ) ;  
 	 	 	 }  
 	 	 }  
 	 	 b r e a k ;  
 	 d e f a u l t :  
 	 	 b r e a k ;  
 	 }  
 }  
  
 v o i d   m e n u _ o p t i o n s ( i n t   o p t i o n )   {  
 	 c o n s t   c h a r *   p a t h ;  
 	 s w i t c h   ( o p t i o n )   {  
 	 c a s e   M E N U _ E X I T :  
 	 	 e x i t ( 0 ) ;  
 	 	 b r e a k ;  
 	 c a s e   M E N U _ R E S E T :  
 	 	 d e l t a _ r e d _ o f _ f i r e   =   0 . 0 f ;  
 	 	 w h i l e   ( p a r t i c l e s . s i z e ( )   <   m a x _ p a r t i c l e )   {  
 	 	 	 p a r t i c l e s . p u s h _ b a c k ( P a r t i c l e ( ) ) ;  
 	 	 }  
 	 	 b r e a k ;  
 	 c a s e   M E N U _ I M P O R T _ C U B E :  
 	 	 l o a d e r . i s _ l o a d e d   =   t r u e ;  
 	 	 p a t h   =   " c u b e . o b j " ;  
 	 	 i f   ( ! l o a d e r . l o a d ( p a t h ) )   {  
 	 	 	 p r i n t f ( " l o a d   o b j e c t   f a i l e d \ n " ) ;  
 	 	 }  
 	 	 b r e a k ;  
 	 }  
 }  
  
 v o i d   c r e a t e _ m e n u ( )   {  
 	 i n t   m e n u ;  
 	 m e n u   =   g l u t C r e a t e M e n u ( m e n u _ o p t i o n s ) ;  
 	 g l u t A d d M e n u E n t r y ( " L o a d " ,   M E N U _ I M P O R T _ C U B E ) ;  
 	 g l u t A d d M e n u E n t r y ( " R e s e t " ,   M E N U _ R E S E T ) ;  
 	 g l u t A d d M e n u E n t r y ( " E x i t " ,   M E N U _ E X I T ) ;  
 	 g l u t A t t a c h M e n u ( G L U T _ R I G H T _ B U T T O N ) ;  
 }  
  
 v o i d   i n i t ( )   {  
 	 g l C l e a r C o l o r ( 0 . 0 f ,   0 . 0 f ,   0 . 0 f ,   0 . 0 f ) ;  
 	 g l S h a d e M o d e l ( G L _ S M O O T H ) ;  
 	 g l C l e a r D e p t h ( 1 . 0 f ) ;  
 	 g l D i s a b l e ( G L _ D E P T H _ T E S T ) ;  
 	 g l E n a b l e ( G L _ B L E N D ) ;  
 	 g l B l e n d F u n c ( G L _ S R C _ A L P H A ,   G L _ O N E ) ;  
 	 g l H i n t ( G L _ P E R S P E C T I V E _ C O R R E C T I O N _ H I N T ,   G L _ N I C E S T ) ;  
 	 g l H i n t ( G L _ P O I N T _ S M O O T H _ H I N T ,   G L _ N I C E S T ) ;  
 	 g l E n a b l e ( G L _ T E X T U R E _ 2 D ) ;  
 	 B u i l d T e x t u r e ( " f i r e . b m p " ,   t e x t u r e [ 0 ] ) ;  
 	 g l B i n d T e x t u r e ( G L _ T E X T U R E _ 2 D ,   t e x t u r e [ 0 ] ) ;  
  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ E M I S S I O N ,   m a t e r i a l _ e m i s s i o n ) ;  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ A M B I E N T ,   m a t e r i a l _ a m b i e n t ) ;  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ D I F F U S E ,   m a t e r i a l _ d i f f u s e ) ;  
 	 g l M a t e r i a l f v ( G L _ F R O N T ,   G L _ S P E C U L A R ,   m a t e r i a l _ s p e c u l a r ) ;  
 	 g l M a t e r i a l f ( G L _ F R O N T ,   G L _ S H I N I N E S S ,   m a t e r i a l _ s h i n i n e s s ) ;  
  
 	 g l L i g h t M o d e l f v ( G L _ L I G H T _ M O D E L _ A M B I E N T ,   a m b i e n t ) ;  
  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ A M B I E N T ,   l i g h t _ a m b i e n t ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ D I F F U S E ,   l i g h t _ d i f f u s e ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ S P E C U L A R ,   l i g h t _ s p e c u l a r ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 0 ,   G L _ P O S I T I O N ,   l i g h t 0 _ p o s i t i o n ) ;  
  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ A M B I E N T ,   l i g h t _ a m b i e n t ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ D I F F U S E ,   l i g h t _ d i f f u s e ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ S P E C U L A R ,   l i g h t _ s p e c u l a r ) ;  
 	 g l L i g h t f v ( G L _ L I G H T 1 ,   G L _ P O S I T I O N ,   l i g h t 1 _ p o s i t i o n ) ;  
  
 	 g l E n a b l e ( G L _ L I G H T 0 ) ;  
 	 g l E n a b l e ( G L _ L I G H T 1 ) ;  
  
 	 f o r   ( i n t   c o u n t   =   0 ;   c o u n t   <   m a x _ p a r t i c l e ;   c o u n t + + )   {  
 	 	 p a r t i c l e s . p u s h _ b a c k ( P a r t i c l e ( ) ) ;  
 	 }  
  
 	 c r e a t e _ m e n u ( ) ;  
 }  
  
 v o i d   p r i n t _ i n f o ( )   {  
 	 s t d : : c o u t   < <   " B o n f i r e "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " A u t h o r :   Y u c h e n   C h e n g   < r u d e i g e r c @ g m a i l . c o m > "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " -   I n s t r u c t i o n s   - "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " e s c   -   E x i t   t h e   p a r t i c l e   s y s t e m . "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " e s c   -   R e s e t   t h e   p a r t i c l e   s y s t e m . "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " N   -   D e c r e a s e   t h e   ' R e d '   o f   R G B A . "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " M   -   I n c r e a s e   t h e   ' R e d '   o f   R G B A . "   < <   s t d : : e n d l ;  
 	 s t d : : c o u t   < <   " -   -   D e c r e a s e   t h e   c o u n t   o f   p a r t i c l e s . "   < <   s t d : : e n d l ;    
 	 s t d : : c o u t   < <   " +   -   I n c r e a s e   t h e   c o u n t   o f   p a r t i c l e s . "   < <   s t d : : e n d l ;  
 }  
  
 i n t   m a i n ( i n t   a r g c ,   c h a r   * a r g v [ ] )   {  
 	 p r i n t _ i n f o ( ) ;  
 	 g l u t I n i t ( & a r g c ,   a r g v ) ;  
 	 g l u t I n i t D i s p l a y M o d e ( G L U T _ D E P T H   |   G L U T _ R G B A   |   G L U T _ D O U B L E ) ;  
 	 g l u t I n i t W i n d o w P o s i t i o n ( 1 0 0 ,   1 0 0 ) ;  
 	 g l u t I n i t W i n d o w S i z e ( 6 0 0 ,   6 0 0 ) ;  
 	 g l u t C r e a t e W i n d o w ( " B o n f i r e " ) ;  
 	 i n i t ( ) ;  
 	 g l u t D i s p l a y F u n c ( d i s p l a y ) ;  
 	 g l u t I d l e F u n c ( i d l e ) ;  
 	 g l u t R e s h a p e F u n c ( r e s h a p e ) ;  
 	 g l u t K e y b o a r d F u n c ( k e y b o a r d ) ;  
 	 g l u t M a i n L o o p ( ) ;  
 	 r e t u r n   0 ;  
 }  
 
