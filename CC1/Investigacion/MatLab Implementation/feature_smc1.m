function [fea]=feature_smc1(I,I_p)
% ========================================================================
%SVD-Based Quality Metric for Image and Video Using Machine Learning 
%Submitted to IEEE Trans. On SMC Part B 2010.
%Authors: Manish Narwaria and Weisi Lin
% ----------------------------------------------------------------------
% Permission to use, copy, or modify this software and its documentation
% for educational and research purposes only and without fee is hereby
% granted, provided that this copyright notice and the original authors'
% names appear on all copies and supporting documentation. This program
% shall not be used, rewritten, or adapted as the basis of a commercial
% software or hardware product without first obtaining permission of the
% authors. The authors make no representations about the suitability of
% this software for any purpose. It is provided "as is" without express
% or implied warranty.
%----------------------------------------------------------------------
%
%----------------------------------------------------------------------
%
%Input : (1) I: reference image
%        (2) I_p: distorted image
%
%Output: 256 dimensional feature vector for further processing with machine
%        learning technique like SVR
%        
%-----------------------------------------------------------------------

% For images whose resolution is not multiple of 128 by 128, please use
% overlapping blocks or zero padding

%------------------------------------------------------------------------

% Inicializar una matriz de vectores de caracteristicos
 feature_vec=zeros(128,16);%%for image size 512 by 512
% Inicializar una matriz de valores caracteristicos
 feature_val=zeros(128,16);

% %feature_vec=zeros(64,64);%%
% %feature_val=zeros(64,64);

% feature_vec=zeros(128,12);%%for image size 512 by 384
% feature_val=zeros(128,12);

    
% feature_vec=zeros(128,24); %%for image size 768 by 512
% feature_val=zeros(128,24);

% Transformamos los valores de la imagen (que vienen en formato int), a formato double
I=im2double(I);
I_p=im2double(I_p);
x=1;
y=1;
z=1;
col=1;


for j=1:4   
    for k=1:4
        %%%%%%%%j and k will be from 1 to 4 for 512 by 512 image;there will be totally 4x4=16 such blocks%%%%%%%%%%%%%%
       
        blck=I(z:z+127, y:y+127); % tomamos un bloque de la imagen original
        blck_p=I_p(z:z+127, y:y+127); % tomamos un bloque de la imagen distorsionada
        [u,s,v]=svd(full(blck));% SVD de la imagen original
        [u1,s1,v1]=svd(full(blck_p)); % SVD de la imagen distosionada
        feature_vec(:,col)=(abs(dot(u,u1))+abs(dot(v,v1)))/2; % obtenemos los vectores caracteristicos
        feature_val(:,col)=(diag(s)-diag(s1)).^2; % obtenemos los valores caracteristicos
        maxi=max(feature_val(:,col));
        if(maxi==0)
          % evitamos hacer divisiones por 0
          maxi=1;
        end
        feature_val(:,col)=feature_val(:,col)/maxi; % normalizamos respecto al valor mas grande
        % avanzamos al siguiente bloque
        y=y+128;
        x=x+1;
        col=col+1;
    end
    % avanzamos al siguiente bloque
    z=z+128;
    y=1;
end
% e=mean2(dis);
% retornamos los valores
fea_vec=(mean(feature_vec'));
fea_val=(mean(feature_val'));
fea=[fea_vec fea_val]; %%final feature vector
return
